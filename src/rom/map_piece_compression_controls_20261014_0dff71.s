.setcpu "65816"
.segment "CODE"
.org $FF71
map_control_0dff71:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
