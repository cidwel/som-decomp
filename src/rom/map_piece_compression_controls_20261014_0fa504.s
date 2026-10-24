.setcpu "65816"
.segment "CODE"
.org $A504
map_control_0fa504:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
