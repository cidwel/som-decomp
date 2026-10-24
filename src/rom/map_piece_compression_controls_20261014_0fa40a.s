.setcpu "65816"
.segment "CODE"
.org $A40A
map_control_0fa40a:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
