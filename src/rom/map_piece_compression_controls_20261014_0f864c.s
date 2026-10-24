.setcpu "65816"
.segment "CODE"
.org $864C
map_control_0f864c:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
