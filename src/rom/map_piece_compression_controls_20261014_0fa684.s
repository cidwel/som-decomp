.setcpu "65816"
.segment "CODE"
.org $A684
map_control_0fa684:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
