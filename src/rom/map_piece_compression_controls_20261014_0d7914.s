.setcpu "65816"
.segment "CODE"
.org $7914
map_control_0d7914:
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
