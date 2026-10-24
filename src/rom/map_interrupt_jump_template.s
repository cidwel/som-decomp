; Jump instructions copied to the map's RAM interrupt slots at0100 and0104.
.setcpu "65816"
map_interrupt_first_target = $00C0A8
map_interrupt_second_target = $00C1CF
.segment "CODE"
.org $BC93
map_interrupt_jump_template:
    jml f:map_interrupt_first_target
    jml f:map_interrupt_second_target
