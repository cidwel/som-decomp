.setcpu "65816"
.segment "CODE"
.org $642C
map_control_0f642c:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
