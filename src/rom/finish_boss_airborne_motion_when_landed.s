; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3766
finish_boss_airborne_motion_when_landed:
    lda a:$0066,X
    beq finish_boss_airborne_motion_when_landed_c2376d
    bpl finish_boss_airborne_motion_when_landed_c23778
finish_boss_airborne_motion_when_landed_c2376d:
    stz a:$0064,X
    stz a:$0066,X
    stz a:$0090,X
    sec
    rts
finish_boss_airborne_motion_when_landed_c23778:
    clc
    rts
