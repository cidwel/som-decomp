.setcpu "65816"
.segment "CODE"
.org $699A
map_control_0f699a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
