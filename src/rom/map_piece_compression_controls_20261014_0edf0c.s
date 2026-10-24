.setcpu "65816"
.segment "CODE"
.org $DF0C
map_control_0edf0c:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
