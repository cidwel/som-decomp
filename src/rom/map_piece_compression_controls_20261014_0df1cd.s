.setcpu "65816"
.segment "CODE"
.org $F1CD
map_control_0df1cd:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
