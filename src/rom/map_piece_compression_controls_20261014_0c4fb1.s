.setcpu "65816"
.segment "CODE"
.org $4FB1
map_control_0c4fb1:
    .byte $E4 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
