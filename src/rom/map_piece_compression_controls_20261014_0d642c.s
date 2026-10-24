.setcpu "65816"
.segment "CODE"
.org $642C
map_control_0d642c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
