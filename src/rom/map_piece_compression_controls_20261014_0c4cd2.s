.setcpu "65816"
.segment "CODE"
.org $4CD2
map_control_0c4cd2:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
