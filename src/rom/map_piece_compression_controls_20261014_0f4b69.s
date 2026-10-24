.setcpu "65816"
.segment "CODE"
.org $4B69
map_control_0f4b69:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
