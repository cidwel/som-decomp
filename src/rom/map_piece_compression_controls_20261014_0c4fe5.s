.setcpu "65816"
.segment "CODE"
.org $4FE5
map_control_0c4fe5:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E3 ; previous-row copy count
