.setcpu "65816"
.segment "CODE"
.org $5891
map_control_0d5891:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
