.setcpu "65816"
.segment "CODE"
.org $6390
map_control_0f6390:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
