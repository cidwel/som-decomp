.setcpu "65816"
.segment "CODE"
.org $A96B
map_control_0fa96b:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
