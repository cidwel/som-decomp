.setcpu "65816"
.segment "CODE"
.org $E5F4
map_control_0fe5f4:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
