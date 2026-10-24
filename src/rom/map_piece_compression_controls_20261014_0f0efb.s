.setcpu "65816"
.segment "CODE"
.org $0EFB
map_control_0f0efb:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
