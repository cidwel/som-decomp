.setcpu "65816"
.segment "CODE"
.org $325C
map_control_0d325c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
