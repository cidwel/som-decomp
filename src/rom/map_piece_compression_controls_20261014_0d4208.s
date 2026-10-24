.setcpu "65816"
.segment "CODE"
.org $4208
map_control_0d4208:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
