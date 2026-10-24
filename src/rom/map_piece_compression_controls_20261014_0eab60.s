.setcpu "65816"
.segment "CODE"
.org $AB60
map_control_0eab60:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E4 ; previous-row copy count
