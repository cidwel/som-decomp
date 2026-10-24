.setcpu "65816"
.segment "CODE"
.org $3F40
map_control_0e3f40:
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
