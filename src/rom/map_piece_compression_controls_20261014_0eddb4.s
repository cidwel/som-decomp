.setcpu "65816"
.segment "CODE"
.org $DDB4
map_control_0eddb4:
    .byte $E8 ; backreference distance high bits
    .byte $45 ; distance low bit/count
