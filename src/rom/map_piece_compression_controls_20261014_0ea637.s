.setcpu "65816"
.segment "CODE"
.org $A637
map_control_0ea637:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
