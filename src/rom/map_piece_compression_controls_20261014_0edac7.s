.setcpu "65816"
.segment "CODE"
.org $DAC7
map_control_0edac7:
    .byte $EC ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E6 ; previous-row copy count
