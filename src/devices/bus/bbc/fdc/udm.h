// license:BSD-3-Clause
// copyright-holders:Nigel Barnes
/**********************************************************************

    Microware / United Disk Memories DDFS FDC

**********************************************************************/


#ifndef MAME_BUS_BBC_FDC_UDM_H
#define MAME_BUS_BBC_FDC_UDM_H

#pragma once

#include "fdc.h"
#include "imagedev/floppy.h"
#include "machine/wd_fdc.h"
#include "formats/acorn_dsk.h"
#include "formats/fsd_dsk.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

class bbc_udm_device :
	public device_t,
	public device_bbc_fdc_interface
{
public:
	// construction/destruction
	bbc_udm_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

protected:
	// device-level overrides
	virtual void device_start() override;

	// optional information overrides
	virtual void device_add_mconfig(machine_config &config) override;
	virtual const tiny_rom_entry *device_rom_region() const override;

	virtual uint8_t read(offs_t offset) override;
	virtual void write(offs_t offset, uint8_t data) override;

private:
	static void floppy_formats(format_registration &fr);

	DECLARE_WRITE_LINE_MEMBER(intrq_w);
	DECLARE_WRITE_LINE_MEMBER(drq_w);
	DECLARE_WRITE_LINE_MEMBER(motor_w);

	required_device<wd2793_device> m_fdc;
	required_device_array<floppy_connector, 2> m_floppy;

	int m_fdc_ie;
};


// device type definition
DECLARE_DEVICE_TYPE(BBC_UDM, bbc_udm_device);


#endif /* MAME_BUS_BBC_FDC_UDM_H */
