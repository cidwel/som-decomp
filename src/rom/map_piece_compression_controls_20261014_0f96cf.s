.setcpu "65816"
.segment "CODE"
.org $96CF
map_control_0f96cf:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
