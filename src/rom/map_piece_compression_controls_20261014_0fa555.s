.setcpu "65816"
.segment "CODE"
.org $A555
map_control_0fa555:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
