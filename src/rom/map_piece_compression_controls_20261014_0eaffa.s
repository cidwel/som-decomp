.setcpu "65816"
.segment "CODE"
.org $AFFA
map_control_0eaffa:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
