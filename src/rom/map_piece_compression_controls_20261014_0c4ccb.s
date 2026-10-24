.setcpu "65816"
.segment "CODE"
.org $4CCB
map_control_0c4ccb:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
