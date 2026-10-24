.setcpu "65816"
.segment "CODE"
.org $1247
map_control_0c1247:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
