.setcpu "65816"
.segment "CODE"
.org $A961
map_control_0fa961:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
