.setcpu "65816"
.segment "CODE"
.org $A32C
map_control_0ea32c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
