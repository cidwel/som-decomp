.setcpu "65816"
.segment "CODE"
.org $5052
map_control_0e5052:
    .byte $EB ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
