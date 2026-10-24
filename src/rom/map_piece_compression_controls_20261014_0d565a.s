.setcpu "65816"
.segment "CODE"
.org $565A
map_control_0d565a:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
