.setcpu "65816"
.segment "CODE"
.org $517A
map_control_0d517a:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
