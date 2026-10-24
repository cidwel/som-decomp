.setcpu "65816"
.segment "CODE"
.org $12DE
map_control_0c12de:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E1 ; previous-row copy count
