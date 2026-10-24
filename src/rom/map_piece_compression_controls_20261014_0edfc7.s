.setcpu "65816"
.segment "CODE"
.org $DFC7
map_control_0edfc7:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
