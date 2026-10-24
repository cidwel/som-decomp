.setcpu "65816"
.segment "CODE"
.org $4F90
map_control_0f4f90:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E6 ; previous-row copy count
