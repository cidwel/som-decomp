.setcpu "65816"
.segment "CODE"
.org $660B
map_control_0e660b:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
