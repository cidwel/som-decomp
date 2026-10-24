.setcpu "65816"
.segment "CODE"
.org $9EBB
map_control_0f9ebb:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
