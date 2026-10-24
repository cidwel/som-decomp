.setcpu "65816"
.segment "CODE"
.org $0D12
map_control_0d0d12:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
