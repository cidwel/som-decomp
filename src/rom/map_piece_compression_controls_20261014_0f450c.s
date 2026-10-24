.setcpu "65816"
.segment "CODE"
.org $450C
map_control_0f450c:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
