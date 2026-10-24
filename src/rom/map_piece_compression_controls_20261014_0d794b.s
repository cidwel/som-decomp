.setcpu "65816"
.segment "CODE"
.org $794B
map_control_0d794b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
