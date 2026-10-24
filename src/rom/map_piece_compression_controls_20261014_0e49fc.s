.setcpu "65816"
.segment "CODE"
.org $49FC
map_control_0e49fc:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E3 ; previous-row copy count
