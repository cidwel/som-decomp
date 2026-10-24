.setcpu "65816"
.segment "CODE"
.org $2906
map_control_0f2906:
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
