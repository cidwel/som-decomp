.setcpu "65816"
.segment "CODE"
.org $2213
map_control_0d2213:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E4 ; previous-row copy count
