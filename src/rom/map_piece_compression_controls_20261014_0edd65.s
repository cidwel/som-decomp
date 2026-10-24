.setcpu "65816"
.segment "CODE"
.org $DD65
map_control_0edd65:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count
