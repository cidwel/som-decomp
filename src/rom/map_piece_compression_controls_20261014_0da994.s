.setcpu "65816"
.segment "CODE"
.org $A994
map_control_0da994:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
