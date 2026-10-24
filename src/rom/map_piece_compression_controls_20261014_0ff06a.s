.setcpu "65816"
.segment "CODE"
.org $F06A
map_control_0ff06a:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
