.setcpu "65816"
.segment "CODE"
.org $92FC
map_control_0d92fc:
    .byte $E8 ; backreference distance high bits
    .byte $4A ; distance low bit/count
    .byte $E2 ; previous-row copy count
