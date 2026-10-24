.setcpu "65816"
.segment "CODE"
.org $1F35
map_control_0f1f35:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
