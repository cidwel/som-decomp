.setcpu "65816"
.segment "CODE"
.org $3DFF
map_control_0e3dff:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
