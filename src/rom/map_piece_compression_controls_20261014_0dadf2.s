.setcpu "65816"
.segment "CODE"
.org $ADF2
map_control_0dadf2:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
